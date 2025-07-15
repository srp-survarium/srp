int __cdecl Scaleform::GFx::ZLibFile::ZLib_InitStream(
        z_stream_s *pstream,
        void *pallocowner,
        unsigned __int8 *pbuffer,
        unsigned int bufferSize)
{
  pstream->opaque = pallocowner;
  pstream->next_out = pbuffer;
  pstream->zalloc = Scaleform::GFx::AMP::ZLibAllocFunc_AMP;
  pstream->zfree = Scaleform::GFx::AMP::ZLibFreeFunc_AMP;
  pstream->next_in = 0;
  pstream->avail_in = 0;
  pstream->avail_out = bufferSize;
  pstream->data_type = 0;
  pstream->adler = 0;
  pstream->reserved = 0;
  return inflateInit_(pstream, "1.2.7", 56);
}
