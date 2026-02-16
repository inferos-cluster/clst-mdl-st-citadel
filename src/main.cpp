#include <inferos/env.h>
#include <spdlog/spdlog.h>
#include <boost/asio.hpp>
#include <iostream>
#include <csignal>
#include <atomic>

using boost::asio::ip::tcp;

namespace {
    std::atomic<bool> running{true};
    
    void signal_handler(int signal) {
        if (signal == SIGINT || signal == SIGTERM) {
            spdlog::info("Received signal {}, shutting down...", signal);
            running = false;
        }
    }
}

int main() {
    // Setup logging
    spdlog::set_level(spdlog::level::info);
    spdlog::info("CLST-MDL-ST-CITADEL starting...");
    
    // Read port from environment
    std::string port_str = inferos::get_env("CLST_MDL_ST_CITADEL_PORT", "8888");
    uint16_t port = static_cast<uint16_t>(std::stoi(port_str));
    
    spdlog::info("Listening on port {}", port);
    
    // Setup signal handlers
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);
    
    try {
        // Create Boost.Asio I/O context
        boost::asio::io_context io_context;
        
        // Create acceptor for incoming connections
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
        
        // Main event loop
        while (running) {
            // Poll for events with timeout
            io_context.poll_one();
            
            // TODO: Accept connections and handle requests
        }
        
        spdlog::info("Shutting down gracefully");
        
    } catch (const std::exception& e) {
        spdlog::error("Fatal error: {}", e.what());
        return 1;
    }
    
    return 0;
}
