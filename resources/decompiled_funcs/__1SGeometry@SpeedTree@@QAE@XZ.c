void __thiscall SpeedTree::SGeometry::~SGeometry(SpeedTree::SGeometry *this)
{
  SpeedTree::SGeometry::Clear(this);
  SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&this->m_sHorzBB);
  SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&this->m_sVertBBs);
}
