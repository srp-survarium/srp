void __cdecl Scaleform::GFx::AS2::SetupAttributes(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *preal)
{
  Scaleform::GFx::AS2::Environment *v2; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::XML::ElementNode *v5; // esi
  Scaleform::GFx::AS2::XMLShadowRef *v6; // edi
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::Object *v9; // ebx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::XML::Attribute *FirstAttribute; // ebx
  char *pData; // esi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  char **pNode; // edx
  Scaleform::GFx::AS2::Object *v17; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::StringManager *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *v22; // [esp+18h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::XMLShadowRef *pshadow; // [esp+1Ch] [ebp-18h]
  char *pstr; // [esp+20h] [ebp-14h]
  Scaleform::GFx::AS2::Value v25; // [esp+24h] [ebp-10h] BYREF

  v2 = penv;
  pHeap = penv->StringContext.pContext->pHeap;
  Alloc = pHeap->Alloc;
  v5 = preal;
  v6 = (Scaleform::GFx::AS2::XMLShadowRef *)preal->pShadow;
  pshadow = v6;
  v7 = (Scaleform::GFx::AS2::Object *)Alloc(pHeap, 52u, 0);
  if ( v7 )
  {
    Scaleform::GFx::AS2::Object::Object(v7, v2);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  pObject = v6->pAttributes.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  v6->pAttributes.pObject = v9;
  if ( Scaleform::GFx::XML::ElementNode::HasAttributes((Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v5) )
  {
    FirstAttribute = v5->FirstAttribute;
    if ( FirstAttribute )
    {
      while ( 1 )
      {
        pData = (char *)FirstAttribute->Value.pNode->pData;
        StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v2->StringContext.pContext);
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager->pStringManager, pData);
        ++StringNode->RefCount;
        v25.T.Type = 5;
        v25.NV.Int32Value = (int)StringNode;
        ++StringNode->RefCount;
        pNode = (char **)FirstAttribute->Name.pNode;
        v17 = v6->pAttributes.pObject;
        pContext = v2->StringContext.pContext;
        LOBYTE(penv) = 0;
        pstr = *pNode;
        v19 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
        v22 = Scaleform::GFx::ASStringManager::CreateStringNode(v19->pStringManager, pstr);
        ++v22->RefCount;
        v17->SetMember(
          &v17->Scaleform::GFx::AS2::ObjectInterface,
          v2,
          (const Scaleform::GFx::ASString *)&v22,
          &v25,
          (const Scaleform::GFx::AS2::PropFlags *)&penv);
        v20 = v22;
        --v22->RefCount;
        if ( !v20->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        Scaleform::GFx::AS2::Value::~Value(&v25);
        if ( StringNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
        FirstAttribute = FirstAttribute->Next;
        if ( !FirstAttribute )
          break;
        v6 = pshadow;
      }
      v5 = preal;
    }
    Scaleform::GFx::XML::ElementNode::ClearAttributes(v5);
  }
}
