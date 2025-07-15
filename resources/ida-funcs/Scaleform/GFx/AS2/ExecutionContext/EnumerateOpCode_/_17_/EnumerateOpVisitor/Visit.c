void __thiscall Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode_::_17_::EnumerateOpVisitor::Visit(
        Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode::__l17::EnumerateOpVisitor *this,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS2::Value *__formal,
        unsigned __int8 flags)
{
  Scaleform::GFx::AS2::Environment *pEnv; // esi
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::ActionLogger *pLog; // eax

  pEnv = this->pEnv;
  v6 = ++pEnv->Stack.pCurrent;
  p_Stack = &pEnv->Stack;
  if ( v6 >= p_Stack->pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
  pCurrent = p_Stack->pCurrent;
  if ( pCurrent )
  {
    pCurrent->T.Type = 5;
    pNode = name->pNode;
    pCurrent->NV.Int32Value = (int)name->pNode;
    ++pNode->RefCount;
  }
  pLog = this->pLog;
  if ( pLog )
    Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::LogAction(
      pLog,
      "---enumerate - Push: %s\n",
      name->pNode->pData);
}
