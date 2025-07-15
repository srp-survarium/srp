void __usercall survarium::flash_text::set_font_size(
        survarium::flash_text *this@<ecx>,
        Scaleform::GFx::DrawTextManager ***a2@<esi>)
{
  const Scaleform::GFx::DrawTextManager::TextParams *DefaultTextParams; // eax
  int v3; // ecx
  const Scaleform::String *v4; // eax
  int v5; // ecx
  int v6; // ecx
  Scaleform::GFx::DrawTextManager::TextParams *v7; // [esp+14h] [ebp-40h] BYREF
  float v8; // [esp+1Ch] [ebp-38h]
  Scaleform::Render::Size<float> result; // [esp+20h] [ebp-34h] BYREF
  float v10[3]; // [esp+28h] [ebp-2Ch] BYREF
  Scaleform::GFx::DrawTextManager::TextParams v11; // [esp+34h] [ebp-20h] BYREF

  ((void (__stdcall *)(_DWORD, _DWORD))(**a2)[2].RefCount)(25.0, 0);
  DefaultTextParams = Scaleform::GFx::DrawTextManager::GetDefaultTextParams(*a2[1]);
  Scaleform::GFx::DrawTextManager::TextParams::TextParams(&v11, DefaultTextParams);
  v3 = (int)*a2;
  v11.FontSize = FLOAT_25_0;
  v4 = (const Scaleform::String *)(*(int (__thiscall **)(int, Scaleform::GFx::DrawTextManager::TextParams **, _DWORD, Scaleform::GFx::DrawTextManager::TextParams *))(*(_DWORD *)v3 + 16))(
                                    v3,
                                    &v7,
                                    0.0,
                                    &v11);
  Scaleform::GFx::DrawTextManager::GetTextExtent(*a2[1], &result, v4, NAN, v7);
  Scaleform::String::DataDesc::Release((Scaleform::String::DataDesc *)(LODWORD(v8) & 0xFFFFFFFC));
  v5 = (int)*a2;
  result.Width = result.Width + 5.0;
  result.Height = result.Height + 5.0;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v5 + 76))(v5, v10);
  v6 = (int)*a2;
  v10[1] = result.Height + v8;
  v10[2] = v10[0] + result.Width;
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v6 + 72))(v6, &result.Height);
  *((_BYTE *)a2[1] + 4) = 1;
  Scaleform::String::DataDesc::Release((Scaleform::String::DataDesc *)(*(_DWORD *)&v11.Underline & 0xFFFFFFFC));
}
