void __cdecl Scaleform::GFx::AS3::XMLParser::CommentExpatCallback(
        Scaleform::GFx::AS3::RefCountBaseGC<328> *userData,
        __m128i *data)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // ebx
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *pNext; // edi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  unsigned int *p_RefCount; // ebp
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLComment *pV; // edi
  unsigned int v9; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *v11; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *p; // [esp+10h] [ebp-Ch]
  Scaleform::GFx::ASString n; // [esp+14h] [ebp-8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLComment> result; // [esp+18h] [ebp-4h] BYREF

  v2 = userData;
  pNext = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)userData->pNext;
  StringManagerRef = pNext->pVM->StringManagerRef;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind((Scaleform::GFx::AS3::XMLParser *)userData, kComment);
  p_RefCount = &v2->RefCount;
  p = (Scaleform::GFx::AS3::Instances::fl::XML *)v2->RefCount;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, data);
  ++StringNode->RefCount;
  n.pNode = StringNode;
  pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceComment(pNext, &result, pNext, &n, p)->pV;
  if ( StringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v9 = *p_RefCount;
  userData = pV;
  if ( v9 && (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v9 + 104))(v9) == 1 )
  {
    (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS3::RefCountBaseGC<328> **))(*(_DWORD *)*p_RefCount + 92))(
      *p_RefCount,
      &userData);
  }
  else
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v2->RefCount,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&userData);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v2[1],
      v2[1].pPrev,
      v2[1].pRCCRaw + 1);
    pRCC = v2[1]._pRCC;
    v11 = v2[1].__vftable;
    if ( (Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *)((char *)v11 + 4 * (_DWORD)pRCC) != (Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *)4 )
    {
      *((_DWORD *)v11 + (_DWORD)pRCC - 1) = userData;
      v12 = userData;
      if ( !userData )
        return;
      ++userData->RefCount;
      v12->RefCount &= 0x8FBFFFFF;
    }
  }
  if ( userData && ((unsigned __int8)userData & 1) == 0 )
  {
    RefCount = userData->RefCount;
    v14 = userData;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      userData->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
    }
  }
}
