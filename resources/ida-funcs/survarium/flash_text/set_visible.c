void __usercall survarium::flash_text::set_visible(survarium::flash_text *this@<esi>, bool value@<al>)
{
  Scaleform::GFx::DrawText *text_impl; // ecx

  if ( this->visible != value )
  {
    text_impl = this->text_impl;
    this->visible = value;
    text_impl->SetVisible(text_impl, value);
    this->owner->need_capture = 1;
  }
}
