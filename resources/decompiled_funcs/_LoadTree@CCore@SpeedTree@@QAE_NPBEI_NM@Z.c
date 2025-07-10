bool __thiscall SpeedTree::CCore::LoadTree(
        SpeedTree::CCore *this,
        unsigned __int8 *src,
        unsigned int count,
        bool a4,
        float a5)
{
  bool v7; // [esp+27h] [ebp-7Dh]
  SpeedTree::CCellBaseTreeItr v8; // [esp+28h] [ebp-7Ch] BYREF
  bool v9; // [esp+97h] [ebp-Dh]
  int v10; // [esp+A0h] [ebp-4h]

  v9 = 0;
  SpeedTree::CCore::DeleteGeometry(this, 0);
  this->m_bOwnsSrtBuffer = a4;
  if ( this->m_bOwnsSrtBuffer )
  {
    this->m_pSrtBuffer = (unsigned __int8 *)SpeedTree::st_new_array<unsigned char>(count, "CCore::st_byte");
    memcpy(this->m_pSrtBuffer, src, count);
  }
  else
  {
    this->m_pSrtBuffer = src;
  }
  SpeedTree::CParser::CParser((SpeedTree::CParser *)&v8);
  v10 = 0;
  v9 = SpeedTree::CParser::Parse((SpeedTree::CParser *)&v8, this->m_pSrtBuffer, count, this, &this->m_sGeometry);
  if ( v9 )
  {
    if ( a5 != 1.0 )
      SpeedTree::CCore::ApplyScale(this, a5);
    SpeedTree::CCore::InventoryGeometry(this);
  }
  v7 = v9;
  v10 = -1;
  SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr(&v8);
  return v7;
}
