#include <memory>
#include <vector>

class Shot;
typedef std::shared_ptr<Shot> ShotPtr;
typedef std::shared_ptr<std::vector<ShotPtr>> VectorPtr_ShotPtr;