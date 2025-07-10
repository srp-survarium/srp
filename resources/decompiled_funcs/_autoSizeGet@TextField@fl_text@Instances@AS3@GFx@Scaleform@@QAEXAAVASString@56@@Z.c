void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::autoSizeGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx
  bool v5; // zf
  int v6; // eax
  int v7; // eax
  Scaleform::GFx::ASString *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASString *v10; // edi
  Scaleform::GFx::ASStringNode *v11; // ecx
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASString *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // ecx
  Scaleform::GFx::ASString *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // ecx
  Scaleform::GFx::ASStringNode *v17; // ecx
  unsigned int *p_RefCount; // eax
  Scaleform::GFx::ASString v19; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::GFx::ASString v20; // [esp+10h] [ebp-8h] BYREF
  Scaleform::GFx::ASString v21; // [esp+14h] [ebp-4h] BYREF

  pObject = this->pDispObj.pObject;
  if ( (pObject[1].ClipDepth & 1) != 0 )
  {
    v6 = (int)pObject[1].pRenNode.pObject[9].pNative & 3;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        if ( v7 != 1 )
          return;
        v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
               this->pTraits.pObject->pVM->StringManagerRef,
               &v19,
               "center");
        pNode = v8->pNode;
        ++v8->pNode->RefCount;
        v10 = result;
        v11 = result->pNode;
        v5 = result->pNode->RefCount-- == 1;
        if ( v5 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        v12 = v19.pNode;
      }
      else
      {
        v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                this->pTraits.pObject->pVM->StringManagerRef,
                &v20,
                "right");
        pNode = v13->pNode;
        ++v13->pNode->RefCount;
        v10 = result;
        v14 = result->pNode;
        v5 = result->pNode->RefCount-- == 1;
        if ( v5 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        v12 = v20.pNode;
      }
    }
    else
    {
      v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              this->pTraits.pObject->pVM->StringManagerRef,
              &v21,
              "left");
      pNode = v15->pNode;
      ++v15->pNode->RefCount;
      v10 = result;
      v16 = result->pNode;
      v5 = result->pNode->RefCount-- == 1;
      if ( v5 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      v12 = v21.pNode;
    }
    v17 = v12;
    p_RefCount = &v12->RefCount;
    v10->pNode = pNode;
    if ( !--*p_RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  }
  else
  {
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                        "none",
                        4u,
                        0);
    ConstStringNode->RefCount += 2;
    v4 = result->pNode;
    v5 = result->pNode->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    result->pNode = ConstStringNode;
    v5 = ConstStringNode->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  }
}
