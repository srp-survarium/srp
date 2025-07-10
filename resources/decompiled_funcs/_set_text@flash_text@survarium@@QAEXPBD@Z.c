void __usercall survarium::flash_text::set_text(survarium::flash_text *this@<esi>, const char *text@<edi>)
{
  Scaleform::GFx::DrawText *text_impl; // ecx
  Scaleform::GFx::DrawText *v3; // ecx
  Scaleform::Render::Size<float> result; // [esp+30h] [ebp-18h] BYREF
  float v5[4]; // [esp+38h] [ebp-10h] BYREF

  this->text_impl->SetText(this->text_impl, text, -1u);
  Scaleform::GFx::DrawTextManager::GetTextExtent(this->owner->text_manager_impl, &result, text, 0.0, 0);
  text_impl = this->text_impl;
  result.Width = result.Width + 5.0;
  result.Height = result.Height + 5.0;
  text_impl->GetRect(text_impl, (Scaleform::Render::Rect<float> *)v5);
  v3 = this->text_impl;
  v5[2] = v5[0] + result.Width;
  v5[3] = v5[1] + result.Height;
  v3->SetRect(v3, (const Scaleform::Render::Rect<float> *)v5);
  this->owner->need_capture = 1;
}
