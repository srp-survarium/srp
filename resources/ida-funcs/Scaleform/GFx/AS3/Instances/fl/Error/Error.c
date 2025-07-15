void __thiscall Scaleform::GFx::AS3::Instances::fl::Error::Error(
        Scaleform::GFx::AS3::Instances::fl::Error *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // edi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::Traits *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  int v9; // eax
  Scaleform::GFx::ASStringNode *v10; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASStringNode *v13; // ecx
  $877A9988573213A5FC37040398A8D661 *v14; // eax

  v2 = t;
  Scaleform::GFx::AS3::Instance::Instance(this, t);
  pObject = this->pTraits.pObject;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::Error_vtbl *)&Scaleform::GFx::AS3::Instances::fl::Error::`vftable';
  p_EmptyStringNode = &pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->message.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v6 = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->name.pNode = v6;
  ++v6->RefCount;
  v7 = this->pTraits.pObject;
  this->ID = 0;
  v8 = &v7->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  this->StackTrace.pNode = v8;
  ++v8->RefCount;
  v9 = (int)v2->GetName(v2, (Scaleform::GFx::ASString *)&t);
  v10 = *(Scaleform::GFx::ASStringNode **)v9;
  ++*(_DWORD *)(*(_DWORD *)v9 + 12);
  pNode = this->name.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v13 = (Scaleform::GFx::ASStringNode *)t;
  v14 = &t->12;
  this->name.pNode = v10;
  if ( !--v14->pPrev )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  Scaleform::GFx::AS3::VM::GetStackTraceASString(this->pTraits.pObject->pVM, &this->StackTrace, "\t");
}
