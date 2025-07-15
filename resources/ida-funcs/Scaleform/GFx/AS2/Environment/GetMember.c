bool __thiscall Scaleform::GFx::AS2::Environment::GetMember(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::ObjectInterface *pthisObj,
        const Scaleform::GFx::ASString *memberName,
        Scaleform::GFx::AS2::Value *pdestVal)
{
  bool v6; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v11; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edi
  char v13; // bl
  unsigned int RefCount; // eax
  unsigned int v15; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::FnCall v17; // [esp+18h] [ebp-24h] BYREF
  char v18; // [esp+48h] [ebp+Ch]

  v6 = pthisObj->GetMember(pthisObj, this, memberName, pdestVal);
  v18 = v6;
  if ( v6 && pdestVal->T.Type == 9 )
  {
    Scaleform::GFx::AS2::Value::GetPropertyValue(pdestVal, this, pthisObj, pdestVal);
    return v18;
  }
  else if ( pdestVal->T.Type == 12 )
  {
    Scaleform::GFx::AS2::Value::ToResolveHandler(pdestVal, &result);
    Function = result.Function;
    if ( result.Function )
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
      pLocalFrame = result.pLocalFrame;
      memset(&v17.ThisFunctionRef, 0, 9);
      v17.ThisPtr = pthisObj;
      v17.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
      v17.Env = this;
      v17.NArgs = 1;
      v17.FirstArgBottomIndex = v11;
      Function->Invoke(Function, &v17, result.pLocalFrame, 0);
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
      pLocalFrame = result.pLocalFrame;
      v13 = 0;
    }
    if ( (result.Flags & 2) == 0 )
    {
      if ( Function )
      {
        RefCount = Function->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    if ( (result.Flags & 1) == 0 && pLocalFrame )
    {
      v15 = pLocalFrame->RefCount;
      if ( (v15 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v15 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
    return v13;
  }
  return v6;
}
