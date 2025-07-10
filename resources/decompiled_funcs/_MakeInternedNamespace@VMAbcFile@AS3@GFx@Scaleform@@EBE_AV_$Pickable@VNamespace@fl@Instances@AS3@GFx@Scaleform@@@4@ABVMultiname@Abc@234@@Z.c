Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::VMAbcFile::MakeInternedNamespace(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::ConstPool *p_Const_Pool; // edi
  const Scaleform::GFx::AS3::Abc::NamespaceInfo *p_any_namespace; // ebx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  const Scaleform::GFx::AS3::Abc::Multiname *v8; // ecx
  int NextIndex; // eax
  int Ind; // eax
  int v11; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString URI; // [esp+10h] [ebp-4h] BYREF

  p_Const_Pool = &this->File.pObject->Const_Pool;
  if ( mn->Ind )
    p_any_namespace = &this->File.pObject->Const_Pool.ConstNamespace.Data.Data[mn->Ind];
  else
    p_any_namespace = &this->File.pObject->Const_Pool.any_namespace;
  StringManagerRef = this->VMRef->StringManagerRef;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (char *)p_any_namespace->NameURI.pStr,
                 p_any_namespace->NameURI.Size);
  v8 = mn;
  URI.pNode = StringNode;
  ++StringNode->RefCount;
  NextIndex = v8->NextIndex;
  if ( NextIndex >= 0 )
  {
    Ind = p_Const_Pool->const_multiname.Data.Data[NextIndex].Ind;
    v11 = Ind ? (int)&p_Const_Pool->ConstNamespace.Data.Data[Ind] : (int)&p_Const_Pool->any_namespace;
    Scaleform::GFx::ASString::Append(&URI, "$", (Scaleform::GFx::ASStringNode *)1);
    mn = (Scaleform::GFx::AS3::Abc::Multiname *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                  StringManagerRef->pStringManager,
                                                  *(char **)(v11 + 4),
                                                  *(_DWORD *)(v11 + 8));
    ++mn->Kind;
    Scaleform::GFx::ASString::Append(&URI, (Scaleform::GFx::ASStringNode *)&mn);
    v12 = (Scaleform::GFx::ASStringNode *)mn;
    --mn->Kind;
    if ( !v12->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(this->VMRef, result, p_any_namespace->Kind, &URI);
  pNode = URI.pNode;
  --URI.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return result;
}
