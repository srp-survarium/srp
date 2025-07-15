Scaleform::String *__cdecl Scaleform::GFx::GetUrlStrGfx(Scaleform::String *result, const Scaleform::String *url)
{
  char *v2; // eax

  Scaleform::String::String(result);
  v2 = (char *)(url->HeapTypeBits & 0xFFFFFFFC);
  if ( (*(_DWORD *)v2 & 0x7FFFFFFFu) > 4
    && !Scaleform::String::CompareNoCase(&v2[(*(_DWORD *)v2 & 0x7FFFFFFF) + 4], ".swf") )
  {
    Scaleform::String::Clear(result);
    Scaleform::String::AppendString(
      result,
      (const __m128i *)((url->HeapTypeBits & 0xFFFFFFFC) + 8),
      (*(_DWORD *)(url->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) - 4);
    Scaleform::String::AppendString(result, (const __m128i *)".gfx", 0xFFFFFFFF);
  }
  return result;
}
