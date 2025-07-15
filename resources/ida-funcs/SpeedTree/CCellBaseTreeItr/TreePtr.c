const struct SpeedTree::CCore *__thiscall SpeedTree::CCellBaseTreeItr::TreePtr(SpeedTree::CCellBaseTreeItr *this)
{
  char *v2; // [esp+0h] [ebp-1Ch]
  char *v3; // [esp+4h] [ebp-18h]

  if ( !this->m_iBaseTreeItr.m_pNode )
    return 0;
  if ( this->m_iBaseTreeItr.m_pPool )
  {
    if ( this->m_iBaseTreeItr.m_pNode )
      v3 = (char *)this->m_iBaseTreeItr.m_pNode + (unsigned int)this->m_iBaseTreeItr.m_pPool->m_pData;
    else
      v3 = 0;
    v2 = v3;
  }
  else
  {
    v2 = 0;
  }
  return *(const struct SpeedTree::CCore **)v2;
}
