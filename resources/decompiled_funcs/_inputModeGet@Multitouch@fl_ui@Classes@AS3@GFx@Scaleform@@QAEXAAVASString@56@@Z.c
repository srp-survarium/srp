void __thiscall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::inputModeGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  __int32 v3; // eax
  __int32 v4; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v6; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v8; // zf
  char *v9; // [esp-Ch] [ebp-18h]
  unsigned int v10; // [esp-8h] [ebp-14h]

  pVM = this->pTraits.pObject->pVM;
  v3 = Scaleform::GFx::MovieImpl::GetMultitouchInputMode((Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM)
     - 1;
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( !v4 )
    {
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          pVM->StringManagerRef->pStringManager,
                          "gesture",
                          7u,
                          0);
      goto LABEL_9;
    }
    if ( v4 == 1 )
    {
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          pVM->StringManagerRef->pStringManager,
                          "mixed",
                          5u,
                          0);
      goto LABEL_9;
    }
    v10 = 4;
    v9 = "none";
  }
  else
  {
    v10 = 10;
    v9 = "touchPoint";
  }
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      pVM->StringManagerRef->pStringManager,
                      v9,
                      v10,
                      0);
LABEL_9:
  v6 = ConstStringNode;
  ConstStringNode->RefCount += 2;
  pNode = result->pNode;
  v8 = result->pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = v6;
  v8 = v6->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}
