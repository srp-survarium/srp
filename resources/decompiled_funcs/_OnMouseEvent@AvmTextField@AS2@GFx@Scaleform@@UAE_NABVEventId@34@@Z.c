char __thiscall Scaleform::GFx::AS2::AvmTextField::OnMouseEvent(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::String event)
{
  bool v2; // zf
  Scaleform::GFx::TextField *v4; // esi
  int v5; // ebp
  unsigned int CharIndexAtPoint; // eax
  int v7; // ebx
  const char *v8; // esi
  char *v9; // esi
  int v10; // eax
  int v11; // edi
  int v12; // edi
  int v13; // edx
  int v14; // esi
  const Scaleform::Render::Text::TextFormat *ptextFmt; // [esp+14h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::AvmTextField *v17; // [esp+18h] [ebp-3Ch]
  Scaleform::Render::Point<float> p; // [esp+1Ch] [ebp-38h] BYREF
  Scaleform::GFx::Value param; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::Value result; // [esp+3Ch] [ebp-18h] BYREF

  v2 = *(_DWORD *)event.HeapTypeBits == 2048;
  v17 = this;
  if ( !v2 )
    return 0;
  v4 = (Scaleform::GFx::TextField *)*((_DWORD *)&this[-1].VariableVal.NV + 3);
  if ( (v4->Flags & 2) != 0 && (v4->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0 )
  {
    v5 = 0;
    if ( Scaleform::GFx::TextField::IsUrlUnderMouseCursor(v4, SBYTE1(event.pData[1].RefCount), &p, 0) )
    {
      CharIndexAtPoint = Scaleform::GFx::TextField::GetCharIndexAtPoint(v4, p.x, p.y);
      if ( CharIndexAtPoint != -1 )
      {
        if ( (unsigned __int8)Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
                                v4->pDocument.pObject->pDocument.pObject,
                                (Scaleform::Render::Text::TextFormat **)&ptextFmt,
                                0,
                                CharIndexAtPoint) )
        {
          if ( Scaleform::Render::Text::TextFormat::IsUrlSet((Scaleform::Render::Text::TextFormat *)ptextFmt) )
          {
            v7 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this[-1].VariableVal.NV + 3) + 16) + 8);
            v8 = (const char *)((ptextFmt->Url.HeapTypeBits & 0xFFFFFFFC) + 8);
            if ( v7 )
            {
              if ( !Scaleform::String::CompareNoCase(v8, "asfunction:", 11) )
              {
                v9 = (char *)(v8 + 11);
                strchr(v9, 0x2Cu);
                v11 = v10;
                Scaleform::String::String(&event);
                param.pObjectInterface = 0;
                param.Type = VT_Undefined;
                if ( v11 )
                {
                  Scaleform::String::AppendString(&event, v9, v11 - (_DWORD)v9);
                  v12 = v11 + 1;
                  v5 = 1;
                  if ( (param.Type & 0x40) != 0 )
                  {
                    param.pObjectInterface->ObjectRelease(param.pObjectInterface, &param, (void *)param.mValue.IValue);
                    param.pObjectInterface = 0;
                  }
                  param.Type = VT_String;
                  param.mValue.IValue = v12;
                }
                else
                {
                  Scaleform::String::operator=(&event, v9);
                }
                v13 = *((_DWORD *)&v17[-1].VariableVal.NV + 3);
                result.pObjectInterface = 0;
                result.Type = VT_Undefined;
                v14 = *(_DWORD *)(v13 + 32);
                if ( v14 && (++*(_DWORD *)(v14 + 4), ((*(_WORD *)(v14 + 62) & 0x400) != 0 ? v14 : 0) != 0) )
                  (*(void (__thiscall **)(_DWORD, int, unsigned int, Scaleform::GFx::Value *, Scaleform::GFx::Value *, int))(**(_DWORD **)(v7 + 12) + 216))(
                    *(_DWORD *)(v7 + 12),
                    (*(_WORD *)(v14 + 62) & 0x400) != 0 ? v14 : 0,
                    (event.HeapTypeBits & 0xFFFFFFFC) + 8,
                    &result,
                    &param,
                    v5);
                else
                  (*(void (__thiscall **)(_DWORD, unsigned int, Scaleform::GFx::Value *, Scaleform::GFx::Value *, int))(**(_DWORD **)(v7 + 12) + 196))(
                    *(_DWORD *)(v7 + 12),
                    (event.HeapTypeBits & 0xFFFFFFFC) + 8,
                    &result,
                    &param,
                    v5);
                if ( v14 )
                  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v14);
                Scaleform::GFx::Value::~Value(&result);
                Scaleform::GFx::Value::~Value(&param);
                Scaleform::String::~String(&event);
              }
            }
          }
        }
      }
    }
  }
  return 1;
}
