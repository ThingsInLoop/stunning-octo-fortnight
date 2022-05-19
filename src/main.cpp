#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <stdlib.h>

/* SOF implementations */
#include <file.h>

/* Run gtests */
int tests(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/* Open documentation (doxygen) */
int docs(int argc, char* argv[]) {
#ifdef SOF_DOCS_DIR
    if (!sof::file_exists(std::string(SOF_DOCS_DIR "/doxygen/index.html"))) {
      std::cout << "Couldn't find documentation. Is documentation installed?\n";
      return EXIT_FAILURE;
    }
    if (!system(NULL)) {
      std::cout << "Shell isn't available. Can't open documentation!\n";
      return EXIT_FAILURE;
    }
    /* Different platforms has different comands for default browser opening. */
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    system("start " SOF_DOCS_DIR "/doxygen/index.html");
#elif defined(unix) || defined(__unix) || defined(__unix__) || \
      defined(__linux) || defined(linux) || defined(__linux)
    system("xdg-open " SOF_DOCS_DIR "/doxygen/index.html");
#elif defined(__APPLE__) || defined(__MACH__)
    system("open " SOF_DOCS_DIR "/doxygen/index.html");
#else
    std::cout << "Couldn't open documentation on this platform!\n";
    return EXIT_FAILURE;
#endif /* platforms */

#else
    std::cout << "Can't get path to directory with sof documentation!\n";
    return EXIT_FAILURE;
#endif /* SOF_DOCS_DIR */
    return EXIT_SUCCESS;
}

int main (int argc, char* argv[]) {
  if (argc > 1 && argv[1] == std::string("tests")) {
    return tests(argc, argv);
  }

  if (argc > 1 && argv[1] == std::string("doc")) {
    return docs(argc, argv);
  }

  std::cout << "stunning-octo-fortnight\n";

  exit(EXIT_SUCCESS);
}
