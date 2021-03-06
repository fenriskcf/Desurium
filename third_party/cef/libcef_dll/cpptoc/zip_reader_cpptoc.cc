// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/stream_reader_cpptoc.h"
#include "libcef_dll/cpptoc/zip_reader_cpptoc.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_zip_reader_t* cef_zip_reader_create(cef_stream_reader_t* stream)
{
  CefRefPtr<CefZipReader> impl = CefZipReader::Create(
      CefStreamReaderCppToC::Unwrap(stream));
  if(impl.get())
    return CefZipReaderCppToC::Wrap(impl);
  return NULL;
}


// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK zip_reader_move_to_first_file(struct _cef_zip_reader_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefZipReaderCppToC::Get(self)->MoveToFirstFile();
}

int CEF_CALLBACK zip_reader_move_to_next_file(struct _cef_zip_reader_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefZipReaderCppToC::Get(self)->MoveToNextFile();
}

int CEF_CALLBACK zip_reader_move_to_file(struct _cef_zip_reader_t* self,
    const cef_string_t* fileName, int caseSensitive)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefZipReaderCppToC::Get(self)->MoveToFile(CefString(fileName),
      caseSensitive ? true : false);
}

int CEF_CALLBACK zip_reader_close(struct _cef_zip_reader_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefZipReaderCppToC::Get(self)->Close();
}

cef_string_userfree_t CEF_CALLBACK zip_reader_get_file_name(
    struct _cef_zip_reader_t* self)
{
  DCHECK(self);
  if(!self)
    return NULL;

  CefString retStr = CefZipReaderCppToC::Get(self)->GetFileName();
  if(!retStr.empty())
    return retStr.DetachToUserFree();
  return NULL;
}

long CEF_CALLBACK zip_reader_get_file_size(struct _cef_zip_reader_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefZipReaderCppToC::Get(self)->GetFileSize();
}

time_t CEF_CALLBACK zip_reader_get_file_last_modified(
    struct _cef_zip_reader_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefZipReaderCppToC::Get(self)->GetFileLastModified();
}

int CEF_CALLBACK zip_reader_open_file(struct _cef_zip_reader_t* self,
    const cef_string_t* password)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefZipReaderCppToC::Get(self)->OpenFile(CefString(password));
}

int CEF_CALLBACK zip_reader_close_file(struct _cef_zip_reader_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefZipReaderCppToC::Get(self)->CloseFile();
}

int CEF_CALLBACK zip_reader_read_file(struct _cef_zip_reader_t* self,
    void* buffer, size_t bufferSize)
{
  DCHECK(self);
  if(!self)
    return -1;

  return CefZipReaderCppToC::Get(self)->ReadFile(buffer, bufferSize);
}

long CEF_CALLBACK zip_reader_tell(struct _cef_zip_reader_t* self)
{
  DCHECK(self);
  if(!self)
    return -1;

  return CefZipReaderCppToC::Get(self)->Tell();
}

int CEF_CALLBACK zip_reader_eof(struct _cef_zip_reader_t* self)
{
  DCHECK(self);
  if(!self)
    return 0;

  return CefZipReaderCppToC::Get(self)->Eof();
}


// CONSTRUCTOR - Do not edit by hand.

CefZipReaderCppToC::CefZipReaderCppToC(CefZipReader* cls)
    : CefCppToC<CefZipReaderCppToC, CefZipReader, cef_zip_reader_t>(cls)
{
  struct_.struct_.move_to_first_file = zip_reader_move_to_first_file;
  struct_.struct_.move_to_next_file = zip_reader_move_to_next_file;
  struct_.struct_.move_to_file = zip_reader_move_to_file;
  struct_.struct_.close = zip_reader_close;
  struct_.struct_.get_file_name = zip_reader_get_file_name;
  struct_.struct_.get_file_size = zip_reader_get_file_size;
  struct_.struct_.get_file_last_modified = zip_reader_get_file_last_modified;
  struct_.struct_.open_file = zip_reader_open_file;
  struct_.struct_.close_file = zip_reader_close_file;
  struct_.struct_.read_file = zip_reader_read_file;
  struct_.struct_.tell = zip_reader_tell;
  struct_.struct_.eof = zip_reader_eof;
}

#ifndef NDEBUG
template<> long CefCppToC<CefZipReaderCppToC, CefZipReader,
    cef_zip_reader_t>::DebugObjCt = 0;
#endif

