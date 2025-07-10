vostok::render::speedtree_tree_component *__thiscall vostok::render::speedtree_tree_component_frond::`vector deleting destructor'(
        vostok::render::speedtree_tree_component *this,
        char a2)
{
  vostok::render::speedtree_tree_component::~speedtree_tree_component(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
