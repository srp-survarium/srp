char __thiscall Scaleform::GFx::AS3::AvmTextField::OnMouseEvent(
        Scaleform::GFx::AS3::AvmTextField *this,
        const Scaleform::GFx::EventId *event)
{
  Scaleform::GFx::TextField *pClassName; // esi
  Scaleform::Render::Text::CompositionStringBase *(__thiscall *BeginIndex)(Scaleform::Render::Text::EditorKitBase *); // ebp
  unsigned int CharIndexAtPoint; // eax
  int v7; // esi
  const char *v8; // edi
  __m128i *v9; // edi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *pDispObj; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v11; // ecx
  const char *v12; // edx
  Scaleform::GFx::AS3::ASVM *v13; // ebp
  Scaleform::GFx::AS3::Object **p_pObject; // eax
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *pObject; // esi
  Scaleform::GFx::ASString *v16; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::RefCountVImpl *v19; // eax
  Scaleform::RefCountVImpl *v20; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v21; // [esp+18h] [ebp-4Ch]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::TextEvent> evt; // [esp+1Ch] [ebp-48h] BYREF
  Scaleform::GFx::ASString result; // [esp+20h] [ebp-44h] BYREF
  const Scaleform::Render::Text::TextFormat *ptextFmt; // [esp+24h] [ebp-40h] BYREF
  Scaleform::GFx::ASString v25; // [esp+28h] [ebp-3Ch] BYREF
  Scaleform::Render::Point<float> p; // [esp+2Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value params[3]; // [esp+34h] [ebp-30h] BYREF

  Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent((Scaleform::GFx::AS3::AvmTextField *)((char *)this - 36), event);
  if ( event->Id != 16777228 )
    return 0;
  pClassName = (Scaleform::GFx::TextField *)this[-1].pClassName;
  BeginIndex = Scaleform::GFx::TextField::GetBeginIndex(pClassName);
  if ( BeginIndex != Scaleform::GFx::TextField::GetEndIndex(pClassName) )
    return 0;
  if ( (pClassName->Flags & 2) != 0 && (pClassName->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0 )
  {
    if ( Scaleform::GFx::TextField::IsUrlUnderMouseCursor(pClassName, event->ControllerIndex, &p, 0) )
    {
      CharIndexAtPoint = Scaleform::GFx::TextField::GetCharIndexAtPoint(pClassName, p.x, p.y);
      if ( CharIndexAtPoint != -1
        && (unsigned __int8)Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
                              pClassName->pDocument.pObject->pDocument.pObject,
                              (Scaleform::Render::Text::TextFormat **)&ptextFmt,
                              0,
                              CharIndexAtPoint)
        && Scaleform::Render::Text::TextFormat::IsUrlSet((Scaleform::Render::Text::TextFormat *)ptextFmt) )
      {
        v7 = *(_DWORD *)(*((_DWORD *)this[-1].pClassName + 4) + 8);
        v8 = (const char *)((ptextFmt->Url.HeapTypeBits & 0xFFFFFFFC) + 8);
        if ( !v7 || Scaleform::String::CompareNoCase(v8, "event:", 6) )
        {
          v19 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v7 + 8) + 12))(v7 + 8, 33);
          v20 = v19;
          if ( v19 )
          {
            Scaleform::RefCountImpl::Release(v19);
            ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::StringDH *))v20->AddRef)(v20, &ptextFmt->Url);
          }
        }
        else
        {
          v9 = (__m128i *)(v8 + 6);
          Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *)(*((_DWORD *)this[-1].pClassName
                                                                                                  + 4)
                                                                                                + 184),
            &result,
            (__m128i *)"link");
          pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
          if ( !pDispObj )
            pDispObj = this[-1].pAS3RawPtr;
          v11 = pDispObj;
          v21 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)pDispObj;
          if ( ((unsigned __int8)pDispObj & 1) != 0 )
          {
            v11 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)pDispObj - 1);
            v21 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)(&pDispObj[-1].pImpl.Owner + 3);
          }
          if ( Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::WillTrigger(v11, &result, 0) )
          {
            evt.pObject = 0;
            Scaleform::GFx::AS3::Value::Value(params, &result);
            v12 = this[-1].pClassName;
            params[1].Flags = 1;
            params[1].value.VS._1.VBool = 1;
            params[2].Flags = 1;
            params[2].value.VS._1.VBool = 1;
            params[1].Bonus.pWeakProxy = 0;
            params[2].Bonus.pWeakProxy = 0;
            v13 = *(Scaleform::GFx::AS3::ASVM **)(*((_DWORD *)v12 + 4) + 40);
            p_pObject = &v13->TextEventExClass.pObject;
            if ( !v13->ExtensionsEnabled )
              p_pObject = &v13->TextEventClass.pObject;
            Scaleform::GFx::AS3::ASVM::_constructInstance(
              v13,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evt,
              *p_pObject,
              3u,
              params);
            pObject = evt.pObject;
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evt.pObject->Target,
              v21);
            v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
                    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *)(*((_DWORD *)this[-1].pClassName + 4) + 184),
                    &v25,
                    v9);
            Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(pObject, v16);
            pNode = v25.pNode;
            --v25.pNode->RefCount;
            if ( !pNode->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
            if ( v13->ExtensionsEnabled )
            {
              pObject[1].__vftable = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent_vtbl *)event->ControllerIndex;
              pObject[1].pRCCRaw = event->AsciiCode;
            }
            Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
              (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v21,
              pObject,
              (Scaleform::GFx::DisplayObject *)this[-1].pClassName);
            `vector destructor iterator'(
              (char *)params,
              0x10u,
              3,
              (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&evt);
          }
          v18 = result.pNode;
          --result.pNode->RefCount;
          if ( !v18->RefCount )
          {
            Scaleform::GFx::ASStringNode::ReleaseNode(v18);
            return 1;
          }
        }
      }
    }
  }
  return 1;
}
