void __thiscall Scaleform::GFx::AS3::Traits::AddSlot(
        Scaleform::GFx::AS3::Traits *this,
        const Scaleform::GFx::AS3::MemberInfo *mi)
{
  const Scaleform::GFx::AS3::MemberInfo *v2; // ebx
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // eax
  int v5; // edi
  Scaleform::GFx::ASStringNode *NamespaceName; // ecx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v10; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  _DWORD *v13; // edi
  const Scaleform::GFx::AS3::SlotInfo *v14; // eax
  bool v15; // zf
  unsigned int *v16; // edx
  Scaleform::GFx::ASString name; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::StringManager *sm; // [esp+14h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex ind; // [esp+18h] [ebp-20h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [esp+1Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::SlotInfo v21; // [esp+20h] [ebp-18h] BYREF

  v2 = mi;
  pVM = this->pVM;
  StringManagerRef = pVM->StringManagerRef;
  v5 = *((_DWORD *)mi + 2);
  ind.Index = (int)this;
  NamespaceName = (Scaleform::GFx::ASStringNode *)mi->NamespaceName;
  v7 = (v5 & 0x2000000 | 0x24000000u) >> 25;
  sm = StringManagerRef;
  if ( NamespaceName && LOBYTE(NamespaceName->pData) )
  {
    if ( NamespaceName != (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::NS_AS3 )
    {
      if ( strcmp((const char *)NamespaceName, Scaleform::GFx::AS3::NS_AS3) )
      {
        pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
               pVM,
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&name,
               (Scaleform::GFx::AS3::Abc::NamespaceKind)(v5 << 12 >> 28),
               NamespaceName)->pV;
        v2 = mi;
        goto LABEL_16;
      }
      v2 = mi;
    }
    pObject = pVM->AS3Namespace.pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    pV = pObject;
  }
  else if ( ((unsigned int)&locret_F0000 & v5) != 0 )
  {
    name.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
    ++name.pNode->RefCount;
    pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
           pVM,
           &result,
           (Scaleform::GFx::AS3::Abc::NamespaceKind)((int)(*((_DWORD *)mi + 2) << 12) >> 28),
           &name)->pV;
    pNode = name.pNode;
    --name.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    v10 = pVM->PublicNamespace.pObject;
    if ( v10 )
      v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
    pV = v10;
  }
LABEL_16:
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      sm->pStringManager,
                      (char *)v2->Name,
                      strlen(v2->Name),
                      0);
  ++ConstStringNode->RefCount;
  ++ConstStringNode->RefCount;
  name.pNode = ConstStringNode;
  sm = (Scaleform::GFx::AS3::StringManager *)ConstStringNode;
  Scaleform::GFx::AS3::SlotInfo::SlotInfo(
    &v21,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const >)pV,
    0,
    v7,
    (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&sm);
  v13 = (_DWORD *)(ind.Index + 20);
  Scaleform::GFx::AS3::Slots::Add((Scaleform::GFx::AS3::Slots *)(ind.Index + 20), &ind, &name, v14);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v21);
  v15 = ConstStringNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  v16 = (unsigned int *)(32 * (ind.Index - *v13) + v13[2] + 8);
  *v16 = *v16 & 0xF800001F
       | (((unsigned int)&loc_1FFFF & (unsigned __int16)*((_DWORD *)mi + 2)) << 10)
       | ((int)(*((_DWORD *)mi + 2) << 7) >> 22) & 0x3E0;
  v15 = ConstStringNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
}
