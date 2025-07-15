void __userpurge survarium::flash_text::set_font_size(
        survarium::flash_text *this@<ecx>,
        Scaleform::GFx::DrawTextManager ***a2@<eax>,
        Scaleform::GFx::DrawTextManager::TextParams *a3@<ebx>,
        int a4@<edi>,
        float a5@<esi>,
        float font_size)
{
  const Scaleform::GFx::DrawTextManager::TextParams *DefaultTextParams; // eax
  Scaleform::GFx::DrawTextManager **v8; // ecx
  const Scaleform::String *v9; // eax
  void *v10; // edi
  Scaleform::GFx::DrawTextManager **v11; // ecx
  Scaleform::GFx::DrawTextManager **v12; // ecx
  _BYTE v14[8]; // [esp+90h] [ebp-38h] BYREF
  int v15; // [esp+98h] [ebp-30h]
  Scaleform::Render::Size<float> result; // [esp+9Ch] [ebp-2Ch] BYREF
  float v17[3]; // [esp+A4h] [ebp-24h] BYREF
  Scaleform::GFx::DrawTextManager::TextParams var18; // [esp+B0h] [ebp-18h] BYREF
  unsigned int retaddr; // [esp+CCh] [ebp+4h]

  ((void (__stdcall *)(_DWORD, _DWORD, int, int))(**a2)[2].RefCount)(LODWORD(font_size), 0, -1, a4);
  DefaultTextParams = Scaleform::GFx::DrawTextManager::GetDefaultTextParams(*a2[1]);
  Scaleform::GFx::DrawTextManager::TextParams::TextParams(&var18, DefaultTextParams);
  v8 = *a2;
  var18.FontSize = font_size;
  v9 = (const Scaleform::String *)((int (__thiscall *)(Scaleform::GFx::DrawTextManager **, _BYTE *, _DWORD, Scaleform::GFx::DrawTextManager::TextParams *))(*v8)->pHeap)(
                                    v8,
                                    v14,
                                    0.0,
                                    &var18);
  Scaleform::GFx::DrawTextManager::GetTextExtent(*a2[1], &result, v9, a5, a3);
  v10 = (void *)(v15 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v15 & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  v11 = *a2;
  result.Width = result.Width + 5.0;
  result.Height = result.Height + 5.0;
  ((void (__thiscall *)(Scaleform::GFx::DrawTextManager **, float *))(*v11)[3].pHeap)(v11, v17);
  v12 = *a2;
  v17[2] = v17[0] + result.Width;
  *(float *)&var18.TextColor.Raw = v17[1] + result.Height;
  ((void (__thiscall *)(Scaleform::GFx::DrawTextManager **, float *))(*v12)[3].pImpl)(v12, v17);
  *((_BYTE *)a2[1] + 4) = 1;
  if ( InterlockedExchangeAdd((volatile LONG *)((retaddr & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)(retaddr & 0xFFFFFFFC));
}
