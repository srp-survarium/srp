survarium::flash_text *__userpurge survarium::flash_text_manager::create_text_w@<eax>(
        survarium::flash_text_manager *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        survarium::flash_text *result,
        wchar_t *text)
{
  Scaleform::GFx::DrawTextManager *v5; // ecx
  Scaleform::GFx::DrawTextManager *v6; // ecx
  Scaleform::Render::Size<float> resulta; // [esp+20h] [ebp-18h] BYREF
  Scaleform::Render::Rect<float> viewRect; // [esp+28h] [ebp-10h] BYREF

  v5 = *(Scaleform::GFx::DrawTextManager **)a2;
  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = 0;
  *(_BYTE *)(a3 + 8) = 0;
  Scaleform::GFx::DrawTextManager::GetTextExtent(v5, &resulta, (const wchar_t *)result, 0.0, 0);
  v6 = *(Scaleform::GFx::DrawTextManager **)a2;
  resulta.Width = resulta.Width + 5.0;
  *(Scaleform::Render::Size<float> *)&viewRect.x2 = resulta;
  viewRect.x1 = 0.0;
  viewRect.y1 = 0.0;
  *(_DWORD *)a3 = Scaleform::GFx::DrawTextManager::CreateText(v6, (const wchar_t *)result, &viewRect, 0, 0xFFFFFFFF);
  *(_BYTE *)(a3 + 8) = 1;
  *(_BYTE *)(a2 + 4) = 1;
  *(_DWORD *)(a3 + 4) = a2;
  return (survarium::flash_text *)a3;
}
