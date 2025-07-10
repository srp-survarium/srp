Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Value *result,
        unsigned int index)
{
  unsigned int v3; // eax
  Scaleform::GFx::AS2::Value *v4; // esi
  unsigned __int8 Type; // dl
  int v6; // edi
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // esi
  unsigned int RefCount; // eax

  v3 = 32 * (this->Stack.Pages.Data.Size - 1) + this->Stack.pCurrent - this->Stack.pPageStart;
  v4 = 0;
  if ( index <= v3 )
    v4 = &this->Stack.Pages.Data.Data[(v3 - index) >> 5]->Values[(v3 - index) & 0x1F];
  Type = v4->T.Type;
  if ( v4->T.Type == 2 )
  {
    v6 = 5;
  }
  else if ( v4->T.Type == 5 )
  {
    v6 = 3;
  }
  else
  {
    if ( Type != 3 && Type != 4 )
    {
      v7 = result;
      result->T.Type = 0;
      return v7;
    }
    v6 = 4;
  }
  v8 = Scaleform::GFx::AS2::Environment::OperatorNew(
         this,
         this->StringContext.pContext->pGlobal.pObject,
         (const Scaleform::GFx::ASString *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount
       + v6,
         1,
         this->Stack.pCurrent - this->Stack.pPageStart + 32 * this->Stack.Pages.Data.Size - 32 - index);
  Scaleform::GFx::AS2::Value::Value(result, v8);
  if ( v8 )
  {
    RefCount = v8->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v8->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return result;
}
