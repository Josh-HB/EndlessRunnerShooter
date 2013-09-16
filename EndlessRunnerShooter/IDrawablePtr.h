#include <memory>
#include <vector>

class IDrawable;
typedef std::shared_ptr<IDrawable> IDrawablePtr;
typedef std::shared_ptr<std::vector<IDrawablePtr>> VectorPtr_IDrawablePtr;