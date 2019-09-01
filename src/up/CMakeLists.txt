add_executable(up
    entity_pool.cpp
    event_logger.cpp
    field.cpp
    frame_timer.cpp
    game.cpp
    main.cpp
    task_pool.cpp
    ticker.cpp
    ui.cpp
    view.cpp
)

find_package(SFML REQUIRED COMPONENTS audio graphics system window)
target_link_libraries(up PRIVATE
    sfml-audio sfml-graphics sfml-system sfml-window)
