void __cdecl Scaleform::GFx::AS2::AvmTextField::CopyToClipboard(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v3; // edi
  int v4; // edi
  int v5; // eax
  const Scaleform::Render::Text::Paragraph *v6; // edx
  unsigned int v7; // ecx
  const Scaleform::Render::Text::Paragraph *v8; // ebp
  const Scaleform::Render::Text::Paragraph *v9; // ebx
  Scaleform::GFx::AS2::Value *v10; // eax
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *v14; // [esp-10h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *v15; // [esp-10h] [ebp-14h]
  bool v16; // [esp+8h] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextField )
  {
    ThisPtr = fn->ThisPtr;
    v3 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : ThisPtr[1].__vftable;
    v4 = *((_DWORD *)v3[1].GetMemberRaw + 41);
    if ( v4 )
    {
      v5 = *(_DWORD *)(v4 + 8);
      v6 = *(const Scaleform::Render::Text::Paragraph **)(v5 + 28);
      v16 = (*(_BYTE *)(v4 + 128) & 4) != 0;
      v7 = *(_DWORD *)(v5 + 32);
      v8 = v6;
      if ( (unsigned int)v6 >= v7 )
        v8 = *(const Scaleform::Render::Text::Paragraph **)(v5 + 32);
      v9 = *(const Scaleform::Render::Text::Paragraph **)(v5 + 28);
      if ( v7 >= (unsigned int)v6 )
        v9 = *(const Scaleform::Render::Text::Paragraph **)(v5 + 32);
      if ( fn->NArgs >= 1 )
      {
        Env = fn->Env;
        v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v16 = Scaleform::GFx::AS2::Value::ToBool(v10, v4, Env);
      }
      if ( fn->NArgs >= 2 )
      {
        v14 = fn->Env;
        v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v8 = (const Scaleform::Render::Text::Paragraph *)Scaleform::GFx::AS2::Value::ToUInt32(v11, v14);
      }
      if ( fn->NArgs >= 3 )
      {
        v15 = fn->Env;
        v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        v9 = (const Scaleform::Render::Text::Paragraph *)Scaleform::GFx::AS2::Value::ToUInt32(v12, v15);
      }
      Scaleform::GFx::Text::EditorKit::CopyToClipboard((Scaleform::GFx::Text::EditorKit *)v4, v8, v9, v16);
    }
  }
}
