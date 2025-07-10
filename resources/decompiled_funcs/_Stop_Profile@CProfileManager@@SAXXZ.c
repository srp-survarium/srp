void __thiscall CProfileManager::Stop_Profile(CProfileNode *this)
{
  if ( CProfileNode::Return(this) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
