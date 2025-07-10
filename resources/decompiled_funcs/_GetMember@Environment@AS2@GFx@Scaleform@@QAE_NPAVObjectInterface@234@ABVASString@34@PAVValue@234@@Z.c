char __thiscall Scaleform::GFx::AS2::Environment::GetMember(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::ObjectInterface *pthisObj,
        const Scaleform::GFx::ASString *memberName,
        Scaleform::GFx::AS2::Value *pdestVal)
{
  char result; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v11; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edi
  char v13; // bl
  unsigned int RefCount; // eax
  unsigned int v15; // eax
  Scaleform::GFx::AS2::FunctionRef resolveHandler; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::FnCall v17; // [esp+18h] [ebp-24h] BYREF
  bool rv; // [esp+48h] [ebp+Ch]

  result = pthisObj->GetMember(pthisObj, this, memberName, pdestVal);
  rv = result;
  if ( result && pdestVal->T.Type == 9 )
  {
    Scaleform::GFx::AS2::Value::GetPropertyValue(pdestVal, this, pthisObj, pdestVal);
    return rv;
  }
  else if ( pdestVal->T.Type == 12 )
  {
    Scaleform::GFx::AS2::Value::ToResolveHandler(pdestVal, &resolveHandler);
    Function = resolveHandler.Function;
    if ( resolveHandler.Function )
    {
      ++this->Stack.pCurrent;
      p_Stack = &this->Stack;
      if ( this->Stack.pCurrent >= this->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&this->Stack);
      pCurrent = p_Stack->pCurrent;
      if ( p_Stack->pCurrent )
      {
        pCurrent->T.Type = 5;
        pNode = memberName->pNode;
        pCurrent->NV.Int32Value = (int)memberName->pNode;
        ++pNode->RefCount;
      }
      Scaleform::GFx::AS2::Value::DropRefs(pdestVal);
      pdestVal->T.Type = 0;
      v11 = this->Stack.pCurrent - this->Stack.pPageStart + 32 * this->Stack.Pages.Data.Size - 32;
      v17.Result = pdestVal;
      pLocalFrame = resolveHandler.pLocalFrame;
      memset(&v17.ThisFunctionRef, 0, 9);
      v17.ThisPtr = pthisObj;
      v17.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
      v17.Env = this;
      v17.NArgs = 1;
      v17.FirstArgBottomIndex = v11;
      Function->Invoke(Function, &v17, resolveHandler.pLocalFrame, 0);
      Scaleform::GFx::AS2::FnCall::~FnCall(&v17);
      if ( p_Stack->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
      --p_Stack->pCurrent;
      if ( this->Stack.pCurrent < this->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&this->Stack);
      v13 = 1;
    }
    else
    {
      pLocalFrame = resolveHandler.pLocalFrame;
      v13 = 0;
    }
    if ( (resolveHandler.Flags & 2) == 0 )
    {
      if ( Function )
      {
        RefCount = Function->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    if ( (resolveHandler.Flags & 1) == 0 && pLocalFrame )
    {
      v15 = pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v15) != 0 )
      {
        pLocalFrame->RefCount = v15 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
    return v13;
  }
  return result;
}
