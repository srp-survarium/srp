void __userpurge survarium::flash_movie::HandleMouseBtn(
        survarium::flash_movie *this@<ecx>,
        float a2@<xmm0>,
        survarium::flash_movie *thisa,
        unsigned int button,
        float y,
        float a6)
{
  Scaleform::GFx::Event::EventType v6; // eax
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::MouseEvent mevent; // [esp+0h] [ebp-1Ch] BYREF

  v6 = Unknown;
  if ( this )
  {
    if ( this == (survarium::flash_movie *)1 )
      v6 = MouseUp;
  }
  else
  {
    v6 = MouseDown;
  }
  m_movie = thisa->m_movie;
  mevent.x = a2;
  mevent.Type = v6;
  mevent.y = y;
  mevent.Modifiers.States = 0;
  mevent.Button = button;
  mevent.MouseIndex = 0;
  mevent.ScrollDelta = 0.0;
  m_movie->HandleEvent(m_movie, &mevent);
}
