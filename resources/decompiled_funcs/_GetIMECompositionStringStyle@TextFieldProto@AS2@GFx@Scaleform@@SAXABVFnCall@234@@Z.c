void __cdecl Scaleform::GFx::AS2::TextFieldProto::GetIMECompositionStringStyle(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::AvmTextField *p_pProto; // ecx
  Scaleform::GFx::AS2::TextFieldObject *TextFieldASObject; // eax
  Scaleform::GFx::AS2::TextFieldObject *v6; // ebx
  Scaleform::GFx::AS2::ObjectInterface *v7; // eax
  Scaleform::GFx::Text::IMEStyle *IMECompositionStringStyles; // ebp
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::Text::IMEStyle::Category v10; // eax
  Scaleform::GFx::ASStringNode *v11; // ecx
  bool v12; // zf
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v14; // ecx
  Scaleform::GFx::AS2::Environment *Env; // [esp-14h] [ebp-1Ch]

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  if ( !v1->ThisPtr )
    return;
  if ( v1->ThisPtr->GetObjectType(v1->ThisPtr) == Object_TextField )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::AvmTextField *)&ThisPtr[-1].pProto;
    else
      p_pProto = 0;
    TextFieldASObject = Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(p_pProto);
    if ( TextFieldASObject )
      TextFieldASObject->RefCount = (TextFieldASObject->RefCount + 1) & 0x8FFFFFFF;
    v6 = TextFieldASObject;
  }
  else
  {
    if ( v1->ThisPtr->GetObjectType(v1->ThisPtr) != Object_TextFieldASObject )
      return;
    v7 = v1->ThisPtr;
    if ( v7 )
    {
      v6 = (Scaleform::GFx::AS2::TextFieldObject *)&v7[-2].pProto;
      if ( v7 == (Scaleform::GFx::AS2::ObjectInterface *)16 )
        return;
      v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      v6 = 0;
    }
  }
  if ( !v6 )
    return;
  IMECompositionStringStyles = Scaleform::GFx::AS2::TextFieldObject::GetIMECompositionStringStyles(v6);
  if ( !IMECompositionStringStyles )
  {
LABEL_23:
    RefCount = v6->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) == 0 )
      return;
    goto LABEL_24;
  }
  Env = v1->Env;
  v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
  Scaleform::GFx::AS2::Value::ToStringImpl(v9, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
  v10 = Scaleform::GFx::AS2::GFx_StringToIMEStyleCategory((Scaleform::GFx::ASString *)&fn);
  if ( v10 < SC_MaxNum )
  {
    Scaleform::GFx::AS2::TextFieldProto::MakeStyle(v1, &IMECompositionStringStyles->HighlightStyles[v10]);
    v14 = (Scaleform::GFx::ASStringNode *)fn;
    v12 = fn->ThisFunctionRef.Function-- == (Scaleform::GFx::AS2::FunctionObject *)1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    goto LABEL_23;
  }
  v11 = (Scaleform::GFx::ASStringNode *)fn;
  v12 = fn->ThisFunctionRef.Function-- == (Scaleform::GFx::AS2::FunctionObject *)1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  RefCount = v6->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
LABEL_24:
    v6->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
  }
}
