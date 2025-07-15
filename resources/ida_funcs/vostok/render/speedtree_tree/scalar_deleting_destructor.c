vostok::render::speedtree_tree *__thiscall vostok::render::speedtree_tree::`scalar deleting destructor'(
        vostok::render::speedtree_tree *this,
        char a2)
{
  vostok::render::speedtree_tree::~speedtree_tree(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
