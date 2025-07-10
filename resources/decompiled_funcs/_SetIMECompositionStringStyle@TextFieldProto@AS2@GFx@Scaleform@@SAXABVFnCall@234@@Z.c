void __usercall Scaleform::GFx::AS2::TextFieldProto::SetIMECompositionStringStyle(
        int a1@<ebp>,
        Scaleform::GFx::ASString a2@<edi>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v3; // ebx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::AvmTextField *p_pProto; // ecx
  Scaleform::GFx::AS2::TextFieldObject *TextFieldASObject; // eax
  Scaleform::GFx::AS2::TextFieldObject *v7; // esi
  Scaleform::GFx::AS2::ObjectInterface *v8; // eax
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::Text::IMEStyle::Category v10; // edi
  Scaleform::GFx::ASStringNode *v11; // ecx
  bool v12; // zf
  unsigned int RefCount; // eax
  const Scaleform::GFx::Text::IMEStyle *IMECompositionStringStyles; // ebp
  Scaleform::Render::Text::HighlightInfo *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // ecx
  unsigned int v17; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-14h] [ebp-7Ch]
  Scaleform::Render::Text::HighlightInfo result; // [esp+4h] [ebp-64h] BYREF
  Scaleform::GFx::Text::IMEStyle imeStyles; // [esp+14h] [ebp-54h] BYREF

  v3 = fn;
  if ( fn->ThisPtr )
  {
    if ( fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
    {
      ThisPtr = v3->ThisPtr;
      if ( ThisPtr )
        p_pProto = (Scaleform::GFx::AS2::AvmTextField *)&ThisPtr[-1].pProto;
      else
        p_pProto = 0;
      TextFieldASObject = Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(p_pProto);
      if ( TextFieldASObject )
        TextFieldASObject->RefCount = (TextFieldASObject->RefCount + 1) & 0x8FFFFFFF;
      v7 = TextFieldASObject;
    }
    else
    {
      if ( v3->ThisPtr->GetObjectType(v3->ThisPtr) != Object_TextFieldASObject )
        return;
      v8 = v3->ThisPtr;
      if ( v8 )
      {
        v7 = (Scaleform::GFx::AS2::TextFieldObject *)&v8[-2].pProto;
        if ( v8 == (Scaleform::GFx::AS2::ObjectInterface *)16 )
          return;
        v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
      }
      else
      {
        v7 = 0;
      }
    }
    if ( v7 )
    {
      if ( v3->NArgs >= 1 )
      {
        Env = v3->Env;
        v9 = Scaleform::GFx::AS2::FnCall::Arg(v3, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(v9, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
        v10 = Scaleform::GFx::AS2::GFx_StringToIMEStyleCategory((Scaleform::GFx::ASString *)&fn);
        if ( v10 >= SC_MaxNum )
        {
          v11 = (Scaleform::GFx::ASStringNode *)fn;
          v12 = fn->ThisFunctionRef.Function-- == (Scaleform::GFx::AS2::FunctionObject *)1;
          if ( v12 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
          RefCount = v7->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            v7->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
          }
          return;
        }
        IMECompositionStringStyles = Scaleform::GFx::AS2::TextFieldObject::GetIMECompositionStringStyles(v7);
        Scaleform::GFx::Text::IMEStyle::IMEStyle(&imeStyles);
        if ( IMECompositionStringStyles )
          Scaleform::GFx::Text::IMEStyle::operator=(&imeStyles, IMECompositionStringStyles);
        v15 = Scaleform::GFx::AS2::TextFieldProto::ParseStyle(
                (int)v3,
                v10,
                &result,
                v3,
                1u,
                (Scaleform::GFx::ASStringNode *)&imeStyles.HighlightStyles[v10],
                a1,
                a2);
        Scaleform::GFx::Text::IMEStyle::SetElement(&imeStyles, v10, v15);
        Scaleform::GFx::AS2::TextFieldObject::SetIMECompositionStringStyles(v7, &imeStyles);
        v16 = (Scaleform::GFx::ASStringNode *)fn;
        v12 = fn->ThisFunctionRef.Function-- == (Scaleform::GFx::AS2::FunctionObject *)1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      }
      v17 = v7->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v17) != 0 )
      {
        v7->RefCount = v17 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
  }
}
