Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Top(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this,
        unsigned int offset)
{
  unsigned int v2; // edx
  Scaleform::GFx::AS2::Value *result; // eax

  v2 = 32 * (this->Pages.Data.Size - 1) + this->pCurrent - this->pPageStart;
  result = 0;
  if ( offset <= v2 )
    return (Scaleform::GFx::AS2::Value *)((char *)this->Pages.Data.Data[(v2 - offset) >> 5] + 16
                                                                                            * ((v2 - offset) & 0x1F));
  return result;
}
