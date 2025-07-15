void __thiscall Scaleform::GFx::AS3::AvmTextField::OnLinkEventEx(
        Scaleform::GFx::AS3::AvmTextField *this,
        Scaleform::GFx::ASStringNode *event,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *pos,
        Scaleform::GFx::AS3::Instances::fl_events::TextEvent_vtbl *controllerIndex)
{
  const char *pClassName; // ecx
  __m128i *v6; // ebp
  __m128i *v7; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *pDispObj; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v9; // ebx
  const char *v10; // edx
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v11; // edi
  Scaleform::GFx::ASString *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  const Scaleform::Render::Text::TextFormat *ptextFmt; // [esp+4h] [ebp-38h] BYREF
  Scaleform::GFx::ASString result; // [esp+8h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::Value params[3]; // [esp+Ch] [ebp-30h] BYREF

  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this[-1].pClassName + 4) + 16))(*((_DWORD *)this[-1].pClassName + 4));
  pClassName = this[-1].pClassName;
  if ( *(_BYTE *)(*(_DWORD *)(*((_DWORD *)pClassName + 4) + 40) + 524)
    && (unsigned __int8)Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
                          *(Scaleform::Render::Text::StyledText **)(*((_DWORD *)pClassName + 32) + 8),
                          (Scaleform::Render::Text::TextFormat **)&ptextFmt,
                          0,
                          (unsigned int)pos)
    && (ptextFmt->PresentMask & 0x100) != 0
    && Scaleform::String::GetLength(&ptextFmt->Url) )
  {
    v6 = (__m128i *)((ptextFmt->Url.HeapTypeBits & 0xFFFFFFFC) + 8);
    if ( event == (Scaleform::GFx::ASStringNode *)2 )
    {
      v7 = (__m128i *)"linkMouseOver";
    }
    else
    {
      if ( event != (Scaleform::GFx::ASStringNode *)3 )
        return;
      v7 = (__m128i *)"linkMouseOut";
    }
    event = Scaleform::GFx::ASStringManager::CreateStringNode(
              *(Scaleform::GFx::ASStringManager **)(*((_DWORD *)this[-1].pClassName + 4) + 432),
              v7);
    ++event->RefCount;
    pDispObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this[-1].pDispObj;
    if ( !pDispObj )
      pDispObj = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this[-1].pAS3RawPtr;
    v9 = pDispObj;
    if ( ((unsigned __int8)pDispObj & 1) != 0 )
      v9 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)pDispObj - 1);
    if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(
           (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v9,
           (const Scaleform::GFx::ASString *)&event,
           0) )
    {
      pos = 0;
      Scaleform::GFx::AS3::Value::Value(params, (const Scaleform::GFx::ASString *)&event);
      v10 = this[-1].pClassName;
      params[1].Flags = 1;
      params[1].Bonus.pWeakProxy = 0;
      params[1].value.VS._1.VBool = 1;
      params[2].Flags = 1;
      params[2].Bonus.pWeakProxy = 0;
      params[2].value.VS._1.VBool = 1;
      Scaleform::GFx::AS3::ASVM::_constructInstance(
        *(Scaleform::GFx::AS3::ASVM **)(*((_DWORD *)v10 + 4) + 40),
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&pos,
        *(Scaleform::GFx::AS3::Object **)(*(_DWORD *)(*((_DWORD *)v10 + 4) + 40) + 484),
        3u,
        params);
      v11 = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)pos;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(pos + 10, v9);
      v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *)(*((_DWORD *)this[-1].pClassName + 4)
                                                                                                  + 184),
              &result,
              v6);
      Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(v11, v12);
      pNode = result.pNode;
      --result.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v11[1].__vftable = controllerIndex;
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v9,
        v11,
        (Scaleform::GFx::DisplayObject *)this[-1].pClassName);
      `vector destructor iterator'(
        (char *)params,
        0x10u,
        3,
        (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pos);
    }
    v14 = event;
    --event->RefCount;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
}
