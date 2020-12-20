#include "hw/l3_DomainLayer.h"

using namespace std;


bool MusicCollection::invariant() const
{
    return _rating >= MIN_RATING
        && _rating <= MAX_RATING    
        && !_track_name.empty() && _track_name.size() <= MAX_LENGTH
        && !_author.empty() && _author.size() <= MAX_LENGTH
        && !_artist.empty() && _artist.size() <= MAX_LENGTH
        && !_duration.empty() && _duration.size() <= MAX_DURATION_LENGTH;
}

MusicCollection::MusicCollection(const std::string & track_name, const std::string & author, const std::string & artist, const std::string & duration, uint16_t rating)
    : _track_name(track_name), _author(author), _artist(artist), _duration(duration), _rating(rating)
{
    assert(invariant());
}

const string & MusicCollection::getTrackName() const
{
    return _track_name;
}

const string & MusicCollection::getAuthor() const
{
    return _author;
}

const string & MusicCollection::getArtist() const
{
    return _artist;
}

const string & MusicCollection::getDuration() const
{
    return _duration;
}

uint16_t MusicCollection::getRating() const
{
    return _rating;
}

bool   MusicCollection::write(ostream& os)
{
    writeString(os, _track_name);
    writeString(os, _author);
    writeString(os, _artist);
    writeString(os, _duration);
    writeNumber(os, _rating);

    return os.good();
}



shared_ptr<ICollectable> ItemCollector::read(istream& is)
{
    string   track_name = readString(is, MAX_LENGTH);
    string   author  = readString(is, MAX_LENGTH);
    string   artist  = readString(is, MAX_LENGTH);
    string duration  = readString(is, MAX_DURATION_LENGTH);
    uint16_t rating  = readNumber<uint16_t>(is);

    return std::make_shared<MusicCollection>(track_name, author, artist, duration, rating);
}
