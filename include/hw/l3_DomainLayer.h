#ifndef HW_L3_DOMAIN_LAYER_H
#define HW_L3_DOMAIN_LAYER_H

#include "hw/l4_InfrastructureLayer.h"

const size_t MAX_LENGTH = 100;
const size_t MAX_DURATION_LENGTH = 5;
const size_t MIN_RATING = 0;
const size_t MAX_RATING = 5;

class MusicCollection : public ICollectable
{
    std::string _track_name;
    std::string _author;
    std::string _artist;
    std::string _duration;
    uint16_t _rating;

protected:
    bool invariant() const;

public:
    MusicCollection() = delete;
    MusicCollection(const MusicCollection & p) = delete;

    MusicCollection & operator = (const MusicCollection & p) = delete;

    MusicCollection(const std::string & track_name, const std::string & author, const std::string & artist, const std::string & duration, uint16_t rating);

    const std::string & getTrackName() const;
    const std::string & getAuthor() const;
    const std::string & getArtist() const;
    const std::string &  getDuration() const;
    uint16_t getRating() const;

    virtual bool   write(std::ostream& os) override;
};


class ItemCollector: public ACollector
{
public:
    virtual std::shared_ptr<ICollectable> read(std::istream& is) override;
};

#endif // HW_L3_DOMAIN_LAYER_H
