void __cdecl Scaleform::GFx::AS2::AvmTextField::AppendHtml(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::TextField *v3; // esi
  Scaleform::GFx::AS2::Value *v4; // eax
  const Scaleform::MemoryHeap *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // edi
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-24h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imageInfoArray; // [esp+4h] [ebp-10h] BYREF

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = v1->ThisPtr;
    v3 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : (Scaleform::GFx::TextField *)ThisPtr[1].__vftable;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v3) && v1->NArgs >= 1 )
    {
      Env = v1->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v4, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
      v5 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v3);
      v6 = (Scaleform::GFx::ASStringNode *)fn;
      memset(&imageInfoArray, 0, 12);
      imageInfoArray.Data.pHeap = v5;
      Scaleform::GFx::TextField::AppendHtml(v3, (const char *)fn->__vftable, 0xFFFFFFFF, 0, &imageInfoArray);
      if ( imageInfoArray.Data.Size )
        Scaleform::GFx::TextField::ProcessImageTags(v3, &imageInfoArray);
      Scaleform::GFx::TextField::SetDirtyFlag(v3);
      Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy>::~ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy>(&imageInfoArray);
      if ( v6->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    }
  }
}
