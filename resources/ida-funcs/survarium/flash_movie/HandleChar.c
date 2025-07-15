void __userpurge survarium::flash_movie::HandleChar(wchar_t c@<ax>, survarium::flash_movie *this)
{
  Scaleform::GFx::Movie *m_movie; // ecx
  int v3; // [esp+0h] [ebp-14h] BYREF
  char v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  char v6; // [esp+Ch] [ebp-8h]

  v5 = c;
  m_movie = this->m_movie;
  v4 = 0;
  v3 = 26;
  v6 = 0;
  m_movie->HandleEvent(m_movie, (const Scaleform::GFx::Event *)&v3);
}
