// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing static and
// virtual method implementations. See the translator.README.txt file in the
// tools directory for more information.
//

#include "libcef_dll/cpptoc/read_handler_cpptoc.h"
#include "libcef_dll/ctocpp/stream_reader_ctocpp.h"


// STATIC METHODS - Body may be edited by hand.

CefRefPtr<CefStreamReader> CefStreamReader::CreateForFile(
    const CefString& fileName)
{
  cef_stream_reader_t* impl =
      cef_stream_reader_create_for_file(fileName.GetStruct());
  if(impl)
    return CefStreamReaderCToCpp::Wrap(impl);
  return NULL;
}

CefRefPtr<CefStreamReader> CefStreamReader::CreateForData(void* data,
    size_t size)
{
  cef_stream_reader_t* impl = cef_stream_reader_create_for_data(data, size);
  if(impl)
    return CefStreamReaderCToCpp::Wrap(impl);
  return NULL;
}

CefRefPtr<CefStreamReader> CefStreamReader::CreateForHandler(
    CefRefPtr<CefReadHandler> handler)
{
  cef_stream_reader_t* impl =
      cef_stream_reader_create_for_handler(CefReadHandlerCppToC::Wrap(handler));
  if(impl)
    return CefStreamReaderCToCpp::Wrap(impl);
  return NULL;
}


// VIRTUAL METHODS - Body may be edited by hand.

size_t CefStreamReaderCToCpp::Read(void* ptr, size_t size, size_t n)
{
  if(CEF_MEMBER_MISSING(struct_, read))
    return 0;

  return struct_->read(struct_, ptr, size, n);
}

int CefStreamReaderCToCpp::Seek(long offset, int whence)
{
  if(CEF_MEMBER_MISSING(struct_, seek))
    return 0;

  return struct_->seek(struct_, offset, whence);
}

long CefStreamReaderCToCpp::Tell()
{
  if(CEF_MEMBER_MISSING(struct_, tell))
    return 0;

  return struct_->tell(struct_);
}

int CefStreamReaderCToCpp::Eof()
{
  if(CEF_MEMBER_MISSING(struct_, eof))
    return 0;

  return struct_->eof(struct_);
}


#ifndef NDEBUG
template<> long CefCToCpp<CefStreamReaderCToCpp, CefStreamReader,
    cef_stream_reader_t>::DebugObjCt = 0;
#endif

