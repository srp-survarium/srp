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
  __m128i *v9; // esi
  int v10; // eax
  int v11; // edi
  int v12; // edi
  int v13; // edx
  int v14; // esi
  Scaleform::Render::Text::TextFormat *v16; // [esp+14h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::AvmTextField *v17; // [esp+18h] [ebp-3Ch]
  Scaleform::Render::Point<float> v18; // [esp+1Ch] [ebp-38h] BYREF
  Scaleform::GFx::Value v19; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::Value v20; // [esp+3Ch] [ebp-18h] BYREF

  v2 = *(_DWORD *)event.HeapTypeBits == 2048;
  v17 = this;
  if ( !v2 )
    return 0;
  v4 = (Scaleform::GFx::TextField *)*((_DWORD *)&this[-1].VariableVal.NV + 3);
  if ( (v4->Flags & 2) != 0 && (v4->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0 )
  {
    v5 = 0;
    if ( Scaleform::GFx::TextField::IsUrlUnderMouseCursor(v4, SBYTE1(event.pData[1].RefCount), &v18, 0) )
    {
      CharIndexAtPoint = Scaleform::GFx::TextField::GetCharIndexAtPoint(v4, v18.x, v18.y);
      if ( CharIndexAtPoint != -1 )
      {
        if ( (unsigned __int8)Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
                                v4->pDocument.pObject->pDocument.pObject,
                                &v16,
                                0,
                                CharIndexAtPoint) )
        {
          if ( Scaleform::Render::Text::TextFormat::IsUrlSet(v16) )
          {
            v7 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this[-1].VariableVal.NV + 3) + 16) + 8);
            v8 = (const char *)((v16->Url.HeapTypeBits & 0xFFFFFFFC) + 8);
            if ( v7 )
            {
              if ( !Scaleform::String::CompareNoCase(v8, "asfunction:", 11) )
              {
                v9 = (__m128i *)(v8 + 11);
                strchr(v9->m128i_i8, 0x2Cu);
                v11 = v10;
                Scaleform::String::String(&event);
                v19.pObjectInterface = 0;
                v19.Type = VT_Undefined;
                if ( v11 )
                {
                  Scaleform::String::AppendString(&event, v9, v11 - (_DWORD)v9);
                  v12 = v11 + 1;
                  v5 = 1;
                  if ( (v19.Type & 0x40) != 0 )
                  {
                    v19.pObjectInterface->ObjectRelease(v19.pObjectInterface, &v19, (void *)v19.mValue.IValue);
                    v19.pObjectInterface = 0;
                  }
                  v19.Type = VT_String;
                  v19.mValue.IValue = v12;
                }
                else
                {
                  Scaleform::String::operator=(&event, v9);
                }
                v13 = *((_DWORD *)&v17[-1].VariableVal.NV + 3);
                v20.pObjectInterface = 0;
                v20.Type = VT_Undefined;
                v14 = *(_DWORD *)(v13 + 32);
                if ( v14 && (++*(_DWORD *)(v14 + 4), ((*(_WORD *)(v14 + 62) & 0x400) != 0 ? v14 : 0) != 0) )
                  (*(void (__thiscall **)(_DWORD, int, unsigned int, Scaleform::GFx::Value *, Scaleform::GFx::Value *, int))(**(_DWORD **)(v7 + 12) + 216))(
                    *(_DWORD *)(v7 + 12),
                    (*(_WORD *)(v14 + 62) & 0x400) != 0 ? v14 : 0,
                    (event.HeapTypeBits & 0xFFFFFFFC) + 8,
                    &v20,
                    &v19,
                    v5);
                else
                  (*(void (__thiscall **)(_DWORD, unsigned int, Scaleform::GFx::Value *, Scaleform::GFx::Value *, int))(**(_DWORD **)(v7 + 12) + 196))(
                    *(_DWORD *)(v7 + 12),
                    (event.HeapTypeBits & 0xFFFFFFFC) + 8,
                    &v20,
                    &v19,
                    v5);
                if ( v14 )
                  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v14);
                Scaleform::GFx::Value::~Value(&v20);
                Scaleform::GFx::Value::~Value(&v19);
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
