Scaleform::String *__thiscall Scaleform::GFx::MovieDataDef::GetResourceName(
        Scaleform::GFx::MovieDataDef *this,
        Scaleform::String *result)
{
  const __m128i *ShortFilename; // eax

  ShortFilename = (const __m128i *)Scaleform::GetShortFilename((const char *)(((int)this->Scaleform::GFx::ResourceReport::__vftable[2].GetResourceName
                                                                             & 0xFFFFFFFC)
                                                                            + 8));
  Scaleform::String::String(result, ShortFilename);
  return result;
}
