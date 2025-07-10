void __thiscall Scaleform::GFx::AS3::Traits::AddSlot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::ASStringNode *mi)
{
  Scaleform::GFx::ASStringNode *v2; // ebx
  const char *pManager; // eax
  Scaleform::GFx::ASStringNode *pLower; // esi
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ecx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi
  Scaleform::GFx::ASStringNode *v9; // eax
  char *pData; // edx
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  const char *v12; // eax
  const Scaleform::GFx::AS3::MemberInfo *ConstStringNode; // esi
  int v14; // eax
  _DWORD *v15; // edi
  unsigned int *v16; // edx
  Scaleform::GFx::AS3::StringManager *sm; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::AbsoluteIndex ind; // [esp+14h] [ebp-1Ch] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::SlotInfo v; // [esp+1Ch] [ebp-14h] BYREF

  v2 = mi;
  pManager = (const char *)mi->pManager;
  pLower = mi->pLower;
  pVM = this->pVM;
  ind.Index = (int)this;
  StringManagerRef = pVM->StringManagerRef;
  v7 = ((unsigned int)&vostok::memory::s_CRT_arena[22351416] & (unsigned int)pLower | 0x24000000) >> 25;
  sm = StringManagerRef;
  mi = (Scaleform::GFx::ASStringNode *)pManager;
  if ( pManager && *pManager )
  {
    if ( pManager == Scaleform::GFx::AS3::NS_AS3 || !strcmp(pManager, Scaleform::GFx::AS3::NS_AS3) )
    {
      pObject = pVM->AS3Namespace.pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    }
    else
    {
      pObject = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
                  pVM,
                  (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&mi,
                  (Scaleform::GFx::AS3::Abc::NamespaceKind)((int)((_DWORD)pLower << 12) >> 28),
                  mi)->pV;
    }
  }
  else if ( ((unsigned int)pLower & 0xF0000) != 0 )
  {
    mi = &StringManagerRef->pStringManager->EmptyStringNode;
    ++mi->RefCount;
    pObject = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
                pVM,
                &result,
                (Scaleform::GFx::AS3::Abc::NamespaceKind)((int)v2->pLower << 12 >> 28),
                (Scaleform::GFx::ASString *)&mi)->pV;
    v9 = mi;
    --mi->RefCount;
    if ( !v9->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  else
  {
    pObject = pVM->PublicNamespace.pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  }
  pData = (char *)v2->pData;
  pStringManager = sm->pStringManager;
  v12 = v2->pData;
  mi = (Scaleform::GFx::ASStringNode *)(v2->pData + 1);
  ConstStringNode = (const Scaleform::GFx::AS3::MemberInfo *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                               pStringManager,
                                                               pData,
                                                               &v12[strlen(v12) + 1] - (const char *)mi,
                                                               0);
  v14 = (int)v;
  ++ConstStringNode[1].Name;
  *(_DWORD *)&v = v7 & 0x1F ^ (v14 & 0xF8000000 | 0x7FFFC00);
  v.pNs.pObject = pObject;
  memset(&v.CTraits, 0, 12);
  v15 = (_DWORD *)(ind.Index + 20);
  mi = (Scaleform::GFx::ASStringNode *)ConstStringNode;
  Scaleform::GFx::AS3::Slots::Add(
    (Scaleform::GFx::AS3::Slots *)(ind.Index + 20),
    &ind,
    (Scaleform::GFx::ASString *)&mi,
    &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  v16 = (unsigned int *)(v15[2] + 28 * (ind.Index - *v15) + 8);
  *v16 = *v16 & 0xF800001F | ((unsigned __int16)v2->pLower << 10) | ((int)v2->pLower << 7 >> 22) & 0x3E0;
  if ( ConstStringNode[1].Name-- == (const char *)1 )
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)ConstStringNode);
}
