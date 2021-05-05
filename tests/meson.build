catch2_dep = dependency('catch2', main : true, fallback : ['catch2', 'catch2_dep'])

testexe = executable('testexe', 'test.cpp',
                     link_with : lib,
                     include_directories : inc,
                    dependencies:[catch2_dep],
                    install: false)
test('discography test', testexe)
