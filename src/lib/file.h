/**
 * @file file.h
 * @brief SOF filesystem functions and classes.
 * @author Sasha K.
 * @date 19 may 2022
 */

#ifndef SOF_LIB_FILE_H_
#define SOF_LIB_FILE_H_

#include <string>
#include <sys/stat.h>

namespace sof {
  /**
   * @brief Check if a file exists
   *
   *  It's `stat()` from stdc usage here because this function is the 
   *  simplest way to get knowledge if file JUST exist or not.
   *
   *  @param path
   *   Path to the file being checked.
   *  @return
   *   `true` - if file exists.<br>
   *   `false` - if not.
   */
  bool file_exists(const std::string& path) {
    struct stat st;
    return (stat(path.c_str(), &st) == 0);
  }
}

#endif /* SOF_LIB_FILE_H_ */
