void __usercall Scaleform::GFx::AS2::AvmTextField::AppendHtml(int a1@<ebp>, const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v2; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::TextField *v4; // esi
  Scaleform::GFx::AS2::Value *v5; // eax
  const Scaleform::MemoryHeap *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // edi
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-24h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imageInfoArray; // [esp+4h] [ebp-10h] BYREF

  v2 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = v2->ThisPtr;
    v4 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : (Scaleform::GFx::TextField *)ThisPtr[1].__vftable;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) && v2->NArgs >= 1 )
    {
      Env = v2->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v2, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
      v6 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v4);
      v7 = (Scaleform::GFx::ASStringNode *)fn;
      memset(&imageInfoArray, 0, 12);
      imageInfoArray.Data.pHeap = v6;
      Scaleform::GFx::TextField::AppendHtml(v4, a1, (char *)fn->__vftable, 0xFFFFFFFF, 0, &imageInfoArray);
      if ( imageInfoArray.Data.Size )
        Scaleform::GFx::TextField::ProcessImageTags(v4, &imageInfoArray);
      Scaleform::GFx::TextField::SetDirtyFlag(v4);
      Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy>::~ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy>(&imageInfoArray);
      if ( v7->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    }
  }
}
