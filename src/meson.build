lib_sources = ['cli.cpp', 'Discography.cpp', 'Track.cpp', 'utils.cpp']
lib = shared_library('lib',
                        lib_sources,
                        include_directories : inc)

discography = executable('discography', 'main.cpp',
                     link_with : lib,
                     include_directories : inc)