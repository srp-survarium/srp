void __thiscall CProfileSample::~CProfileSample(CProfileSample *this)
{
  if ( CProfileNode::Return((CProfileNode *)this) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
