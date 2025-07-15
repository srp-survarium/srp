void __fastcall survarium::flash_movie::HandleKeyboard(
        int a1,
        Scaleform::Key::Code scan,
        survarium::flash_movie *this,
        survarium::flash_movie::keyb_btn_action action)
{
  Scaleform::GFx::KeyEvent ev; // [esp+0h] [ebp-1Ch] BYREF

  ev.Modifiers.States = 0;
  ev.AsciiCode = 0;
  ev.WcharCode = 0;
  ev.KeyboardIndex = 0;
  ev.KeyCode = scan;
  ev.Type = (action != kb_key_down) + 5;
  this->m_movie->HandleEvent(this->m_movie, &ev);
}
