void __cdecl Scaleform::GFx::AS2::AvmTextField::GetTextFormat(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v2; // ebp
  unsigned int v3; // ebx
  unsigned int v4; // edi
  Scaleform::GFx::AS2::Value *v5; // eax
  long double v6; // st7
  int NArgs; // eax
  Scaleform::GFx::AS2::Value *v8; // eax
  long double v9; // st7
  Scaleform::GFx::AS2::Value *v10; // eax
  long double v11; // st7
  bool (__thiscall *GetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *); // edx
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::TextFormatObject *v14; // eax
  Scaleform::GFx::AS2::TextFormatObject *v15; // eax
  Scaleform::GFx::AS2::TextFormatObject *v16; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-58h]
  Scaleform::GFx::AS2::Environment *v20; // [esp-10h] [ebp-58h]
  Scaleform::GFx::AS2::Environment *v21; // [esp-10h] [ebp-58h]
  Scaleform::Render::Text::ParagraphFormat pdestParaFmt; // [esp+Ch] [ebp-3Ch] BYREF
  Scaleform::Render::Text::TextFormat pdestTextFmt; // [esp+20h] [ebp-28h] BYREF

  if ( !fn->ThisPtr || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_TextField )
    goto LABEL_26;
  ThisPtr = fn->ThisPtr;
  if ( (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 )
    v2 = 0;
  else
    v2 = ThisPtr[1].__vftable;
  v3 = 0;
  v4 = -1;
  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
    if ( v6 < 0.0 )
      v6 = 0.0;
    v3 = (__int64)v6;
  }
  NArgs = fn->NArgs;
  if ( NArgs < 2 )
  {
    if ( NArgs >= 1 )
    {
      v21 = fn->Env;
      v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v11 = Scaleform::GFx::AS2::Value::ToNumber(v10, v21) + 1.0;
      if ( v11 < 0.0 )
        v11 = 0.0;
      v4 = (__int64)v11;
    }
  }
  else
  {
    v20 = fn->Env;
    v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
    v9 = Scaleform::GFx::AS2::Value::ToNumber(v8, v20);
    if ( v9 < 0.0 )
      v9 = 0.0;
    v4 = (__int64)v9;
  }
  if ( v3 <= v4 )
  {
    Scaleform::Render::Text::TextFormat::TextFormat(&pdestTextFmt, fn->Env->StringContext.pContext->pHeap);
    GetMemberRaw = v2[1].GetMemberRaw;
    pdestParaFmt.RefCount = 1;
    memset(&pdestParaFmt.pTabStops, 0, 16);
    Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
      *((Scaleform::Render::Text::StyledText **)GetMemberRaw + 2),
      &pdestTextFmt,
      &pdestParaFmt,
      v3,
      v4);
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v14 = (Scaleform::GFx::AS2::TextFormatObject *)pHeap->Alloc(pHeap, 112u, 0);
    if ( v14 )
    {
      Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(v14, fn->Env);
      v16 = v15;
    }
    else
    {
      v16 = 0;
    }
    Scaleform::GFx::AS2::TextFormatObject::SetTextFormat(
      v16,
      (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
      &pdestTextFmt);
    Scaleform::GFx::AS2::TextFormatObject::SetParagraphFormat(v16, (unsigned int)&fn->Env->StringContext, &pdestParaFmt);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v16);
    if ( v16 )
    {
      RefCount = v16->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v16->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
      }
    }
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&pdestParaFmt);
    Scaleform::Render::Text::TextFormat::~TextFormat(&pdestTextFmt);
  }
  else
  {
LABEL_26:
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 0;
  }
}
