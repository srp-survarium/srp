char __thiscall SpeedTree::CParser::ParseGeometry(
        SpeedTree::CParser *this,
        struct SpeedTree::CParser::STriListTmp *a2,
        struct SpeedTree::CParser::STriListTmp *a3,
        struct SpeedTree::CParser::STriListTmp *a4,
        struct SpeedTree::CParser::SLeafCardsTmp *a5)
{
  char v7; // [esp+7h] [ebp-1h]

  v7 = 0;
  if ( SpeedTree::CParser::ParseTriangleListType(this, a2)
    && SpeedTree::CParser::ParseTriangleListType(this, a3)
    && SpeedTree::CParser::ParseTriangleListType(this, a4) )
  {
    return SpeedTree::CParser::ParseLeafCards(this, a5);
  }
  return v7;
}
