Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::FnCall::Arg(Scaleform::GFx::AS2::FnCall *this, int n)
{
  int FirstArgBottomIndex; // edx
  Scaleform::GFx::AS2::Environment *Env; // ecx
  unsigned int v4; // edx
  int v5; // esi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // ecx
  Scaleform::GFx::AS2::Value *result; // eax

  FirstArgBottomIndex = this->FirstArgBottomIndex;
  Env = this->Env;
  v4 = FirstArgBottomIndex - n;
  v5 = (char *)Env->Stack.pCurrent - (char *)Env->Stack.pPageStart;
  p_Stack = &Env->Stack;
  result = 0;
  if ( v4 <= 32 * (p_Stack->Pages.Data.Size - 1) + (v5 >> 4) )
    return (Scaleform::GFx::AS2::Value *)((char *)p_Stack->Pages.Data.Data[v4 >> 5] + 16 * (v4 & 0x1F));
  return result;
}
