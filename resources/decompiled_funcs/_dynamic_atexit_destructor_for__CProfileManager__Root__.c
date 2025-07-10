void __cdecl dynamic_atexit_destructor_for__CProfileManager::Root__()
{
  CProfileNode *Child; // esi
  CProfileNode *Sibling; // esi

  Child = CProfileManager::Root.Child;
  if ( CProfileManager::Root.Child )
  {
    CProfileNode::~CProfileNode(CProfileManager::Root.Child);
    operator delete(Child);
  }
  Sibling = CProfileManager::Root.Sibling;
  if ( CProfileManager::Root.Sibling )
  {
    CProfileNode::~CProfileNode(CProfileManager::Root.Sibling);
    operator delete(Sibling);
  }
}
