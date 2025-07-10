Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Value *result,
        const Scaleform::GFx::AS2::Value *v)
{
  unsigned __int8 Type; // cl
  int v5; // ebx
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Object *v8; // edi
  unsigned int RefCount; // eax

  Type = v->T.Type;
  if ( v->T.Type == 2 )
  {
    v5 = 5;
  }
  else if ( v->T.Type == 5 )
  {
    v5 = 3;
  }
  else
  {
    if ( Type != 3 && Type != 4 )
    {
      v6 = result;
      result->T.Type = 0;
      return v6;
    }
    v5 = 4;
  }
  ++this->Stack.pCurrent;
  p_Stack = &this->Stack;
  if ( this->Stack.pCurrent >= this->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&this->Stack);
  if ( p_Stack->pCurrent )
    Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, v);
  v8 = Scaleform::GFx::AS2::Environment::OperatorNew(
         this,
         this->StringContext.pContext->pGlobal.pObject,
         (const Scaleform::GFx::ASString *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount
       + v5,
         1,
         this->Stack.pCurrent - this->Stack.pPageStart + 32 * this->Stack.Pages.Data.Size - 32);
  if ( p_Stack->pCurrent->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
  if ( --p_Stack->pCurrent < p_Stack->pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
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
